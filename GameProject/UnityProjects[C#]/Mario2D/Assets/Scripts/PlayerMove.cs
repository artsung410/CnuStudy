using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public GameManager gameManager;
    public AudioClip audioJump;
    public AudioClip audioAttack;
    public AudioClip audioDamaged;
    public AudioClip audioItem;
    public AudioClip audioDie;
    public AudioClip audioFinish;
    public float maxSpeed;
    public float jumpPower;
    Rigidbody2D rigid;

    CapsuleCollider2D playerCollider;
    SpriteRenderer spriteRenderer;
    Animator anim;
    AudioSource audioSource;
    // Start is called before the first frame update
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        anim = GetComponent<Animator>();
        playerCollider = GetComponent<CapsuleCollider2D>();
        audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame

    void PlaySound(string action)
    {
        switch (action) {
            case "JUMP":
                audioSource.clip = audioJump;
                audioSource.Play();
                break;
            case "ATTACK":
                audioSource.clip = audioAttack;
                audioSource.Play();
                break;
            case "DAMAGED":
                audioSource.clip = audioDamaged;
                audioSource.Play();
                break;
            case "ITEM":
                audioSource.clip = audioItem;
                audioSource.Play();
                break;
            case "DIE":
                audioSource.clip = audioDie;
                audioSource.Play();
                break;
            case "FINISH":
                audioSource.clip = audioFinish;
                audioSource.Play();
                break;   
        }
    }

    void Update()
    {
        Move();
        speed();
        flip();
        ani();
        jump();
        
    }
    void FixedUpdate() 
    {
        landing();
    }
    void Move()
    {
        //Move Speed
        float h = Input.GetAxisRaw("Horizontal");
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse);

        //Max Speed
        if (rigid.velocity.x > maxSpeed) //Right Max Speed
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y);
        else if (rigid.velocity.x < maxSpeed*(-1)) //Left Max Speed
            rigid.velocity = new Vector2(maxSpeed*(-1), rigid.velocity.y);
    }

    void jump()
    {
        // 무한점프 방지 : !anim.GetBool("isJumping")
        if (Input.GetButtonDown("Jump") && !anim.GetBool("isJumping"))
        {
            rigid.AddForce(Vector2.up * jumpPower, ForceMode2D.Impulse);
            anim.SetBool("isJumping", true);
            PlaySound("JUMP");
        }
    }

    void speed()
    {
        //Stop Speed
        if (Input.GetButtonUp("Horizontal"))
            rigid.velocity = new Vector2(rigid.velocity.normalized.x * 0.0001f, rigid.velocity.y);        
    }
    void flip()
    {
        //Direction Sprite[bool]
        if (Input.GetButton("Horizontal"))
            if (Input.GetAxisRaw("Horizontal") == -1)
                spriteRenderer.flipX = true;
            else
                spriteRenderer.flipX = false;
    }

    void ani()
    {
        //Animation[bool]
        if (Mathf.Abs(rigid.velocity.x) < 0.3)
        {
            anim.SetBool("isWalking", false);
        }

        else if (Mathf.Abs(rigid.velocity.x) > 0.3)
        {
            anim.SetBool("isWalking", true);
        }
    }
    void landing()
    {
        //Landing Platform
        if(rigid.velocity.y < 0)
        {
            // Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0));
            // 빔쏘고 맞은 오브젝트의 정보를 담는다. 빔이 닫지 않으면 rayHit.collider = null이 됨..
            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, 1, LayerMask.GetMask("platform"));
            Debug.Log(rayHit.collider);
            if (rayHit.collider != null)
            {
                if(rayHit.distance < 0.5f)
                    anim.SetBool("isJumping", false);
            }
        }
    }

    // 몬스터 처리
    void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.tag == "Enemy")
        {
            //Attack
            if (rigid.velocity.y < 0 && transform.position.y > collision.transform.position.y)
            {
                onAttack(collision.transform);
            }
            else //Damaged
                OnDamaged(collision.transform.position);
        }
    }

    // 동전 줍줍
    void OnTriggerEnter2D(Collider2D collision) 
    {
        if (collision.gameObject.tag == "Item")
        {
            // Point
            bool isBronze = collision.gameObject.name.Contains("Bronze_coin");
            bool isSilver = collision.gameObject.name.Contains("Silver_coin");
            bool isGold = collision.gameObject.name.Contains("Gold_coin");

            if (isBronze)
                gameManager.stagePoint += 50;
            else if (isSilver)
                gameManager.stagePoint += 100;
            else if (isGold)
                gameManager.stagePoint += 150;            
          
            // Deactive Item
            collision.gameObject.SetActive(false);
            // Sound
            PlaySound("ITEM");
        }
        else if (collision.gameObject.tag == "Finish")
        {
            // Next Stage
            gameManager.NextStage();
            // Sound
            PlaySound("FINISH");
        }
    }

    void onAttack(Transform enemy)
    {
        // Point
        gameManager.stagePoint += 100;

        // Sound
        PlaySound("ATTACK");     

        // Reaction Force
        rigid.AddForce(Vector2.up * 10, ForceMode2D.Impulse);

        // Enemy Die
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>();
        enemyMove.OnDamaged();

    }
    void OnDamaged(Vector2 targetPos)
    {
        // Health Down
        gameManager.HealthDown();

        // Change Layer (Immortal Active)
        gameObject.layer = 11;

        spriteRenderer.color = new Color(1, 1, 1, 0.4f);

        // Reaction Force
        int dirc = transform.position.x - targetPos.x > 0 ? 1 : -1;
        rigid.AddForce(new Vector2(dirc, 1) * 10, ForceMode2D.Impulse);

        // Sound
        PlaySound("DAMAGED");       

        // Animation
        anim.SetTrigger("doDamaged");
        Invoke("OffDamaged", 3);
    }

    void OffDamaged()
    {
        gameObject.layer = 10;
        spriteRenderer.color = new Color(1, 1, 1, 1);
    }

    public void OnDie()
    {
        spriteRenderer.color = new Color(1, 1, 1, 0.4f);
        //Sprite Flip Y
        spriteRenderer.flipY = true;
        //Collider Disable
        playerCollider.enabled = false;
        //Die Effect Jump
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse);
        // Sound
        PlaySound("DIE");        
    }

    public void VelocityZero()
    {
        rigid.velocity = Vector2.zero;
    }
}
