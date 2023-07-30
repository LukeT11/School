using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PropellerBehavior : MonoBehaviour
{
    private float turnSpeed = 800.0f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // rotates the propeller
        transform.Rotate(Vector3.forward, Time.deltaTime * turnSpeed);
    }
}
