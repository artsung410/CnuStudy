using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallMove : MonoBehaviour
{
    Rigidbody rigid;
    // Start is called before the first frame update
    void Start()
    {
        rigid = GetComponent<Rigidbody>();
        // rigid.AddForce(Vector3.up * 50, ForceMode.Impulse);
    }

    // Update is called once per frame

    void FixedUpdate()
    {
        move();
    }

    void Update()
    {
        jump();
    }

    void move()
    {
        float h = Input.GetAxisRaw("Horizontal");
        float v = Input.GetAxisRaw("Vertical");
        Vector3 vec = new Vector3(h, 0, v);

        rigid.AddForce(vec, ForceMode.Impulse);
    }

    void jump()
    {
        if (Input.GetKeyDown(KeyCode.Space))
            rigid.AddForce(Vector3.up * 50, ForceMode.Impulse);
        Debug.Log(rigid.velocity);
    }

    private void OnTriggerStay(Collider other)
    {
        if (other.name == "Cube")
            rigid.AddForce(Vector3.up * 2, ForceMode.Impulse);
    }

    public void oump()
    {
        rigid.AddForce(Vector3.up * 20, ForceMode.Impulse);
    }

}