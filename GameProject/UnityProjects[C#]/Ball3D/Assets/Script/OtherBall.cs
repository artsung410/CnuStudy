using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OtherBall : MonoBehaviour
{
    MeshRenderer mesh;
    Material mat;

    // Start is called before the first frame update
    void Start()
    {
        mesh = GetComponent<MeshRenderer>();
        mat = mesh.material;
    }
    //충돌 시작했을 때
    private void OnCollisionEnter(Collision collision) 
    {

        if(collision.gameObject.name == "MyBall")
        {
            mat.color = new Color(0, 0, 0);
        }

    }

    //충돌 벗어났을 때
    private void OnCollisionExit(Collision collision) 
    {

        if(collision.gameObject.name == "MyBall")
        {
            mat.color = new Color(1, 1, 1);
        }

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
