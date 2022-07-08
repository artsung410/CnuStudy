using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float Speed = 1f;
    public bool UseSpeed = false;

    private PlayerInput _input;
    private Rigidbody _rigidbody;
    // Update is called once per frame
    void Start()
    {
        // input 값 할당
        _input = GetComponent<PlayerInput>();
        // 힘을가지기위해 rigidbody 할당
        _rigidbody = GetComponent<Rigidbody>();
    }
    void Update()
    {
        // 각 방향에 따라 힘을 가하기
        float xSpeed = _input.X * Speed;
        float zSpeed = _input.Y * Speed;

        if (UseSpeed)
        {
            _rigidbody.velocity = new Vector3(xSpeed, 0f, zSpeed);
        }
        else
        {
            _rigidbody.AddForce(xSpeed, 0f, zSpeed);
        }

        // if(_input.Up)
        // {
        //     _rigidbody.AddForce(0,0,-Speed);
        // }
        // if(_input.Down)
        // {
        //     _rigidbody.AddForce(0,0,Speed);
        // }
        // if(_input.Left)
        // {
        //     _rigidbody.AddForce(Speed, 0, 0);
        // }
        // if(_input.Right)
        // {
        //     _rigidbody.AddForce(-Speed, 0, 0);
        // }
    }
}
