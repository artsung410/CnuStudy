using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerLife : MonoBehaviour
{
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            Die();
        }
    }

    // 죽음 === 삭제
    public void Die()
    {
        // 오브젝트 삭제
        gameObject.SetActive(false);
    }
}
