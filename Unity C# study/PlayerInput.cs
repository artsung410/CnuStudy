using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerInput : MonoBehaviour
{
    // 프로퍼티로 bool타입의 up, down, left, right만들기
    public float X {get; private set;}
    public float Y {get; private set;}

    // Update is called once per frame
    void Update()
    {
       // 이전값 날리고, 기본값으로 초기화
        X = Y =0f;

       // 현재 프레임의 입력값을 저장
        X = Input.GetAxis("Horizontal");
        Y = Input.GetAxis("Vertical");

        // Up = Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.W);
        // Down = Input.GetKey(KeyCode.DownArrow) || Input.GetKey(KeyCode.S);
        // Left = Input.GetKey(KeyCode.LeftArrow) || Input.GetKey(KeyCode.A);
        // Right = Input.GetKey(KeyCode.RightArrow) || Input.GetKey(KeyCode.D);
       
    }
}
