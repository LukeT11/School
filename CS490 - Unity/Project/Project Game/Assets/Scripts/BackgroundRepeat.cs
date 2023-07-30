using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BackgroundRepeat : MonoBehaviour
{
    private Vector3 startPos;
    private float repeatNum;

    // Start is called before the first frame update
    void Start()
    {
        startPos = transform.position;
        repeatNum = (GetComponent<BoxCollider>().size.x / 2) * transform.localScale.x;
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.z < startPos.z - repeatNum)
        {
            transform.position = startPos;
        }
    }
}
