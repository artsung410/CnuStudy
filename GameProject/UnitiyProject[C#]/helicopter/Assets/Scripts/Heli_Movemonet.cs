using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Heli_Movemonet : MonoBehaviour
{
    public GameObject MainProp; // 큰 프로펠러 오브젝트 프로퍼티 만들기
    public GameObject TailProp; // 작은 프로펠러 오브젝트 프로퍼티 만들기

    private Heli_Input _input;
    private Rigidbody _rigidbody;

    private bool propOn = false; // 프로펠러가 도는지 확인(시동)

    public float _propSpeed = 500f; // 프로펠러 스피드 설정 기본은 1000
    public float _moveSpeed = 1f; // 헬기의 전후진, 회전 속도

    void Awake()
    {
        _input = GetComponent<Heli_Input>();
        _rigidbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        float xSpeed = _input.X * _moveSpeed; // 회축 입력값 받아오기
        float zSpeed = _input.Y * _moveSpeed; // 종축 입력값 받아오기

        // Z키를 누를때마다 시동이 켜지거나 꺼진다.
        if(_input.EngineOnOff)
        {
            propOn = !propOn;
        }

        // 헬기가 시동이 걸렸을때만 움직이게 만든다.
        if(propOn)
        {
            MainProp.transform.Rotate(0f, _propSpeed * Time.deltaTime, 0f);
            _rigidbody.AddForce(0f, zSpeed, 0f);
            gameObject.transform.Rotate(0f, xSpeed, 0f);
        }
        else
        {
            _rigidbody.AddForce(0f, -1f, 0f);
        }

        if(xSpeed != 0)
        {
            TailProp.transform.Rotate(_propSpeed * Time.deltaTime, 0f, 0f);
        }
    }
}
