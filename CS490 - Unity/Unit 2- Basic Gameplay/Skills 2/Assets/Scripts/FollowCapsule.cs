using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCapsule : MonoBehaviour
{
    public GameObject capsule;
    private Vector3 cameraPosition = new Vector3(0, 4, -10);

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = capsule.transform.position + cameraPosition;
    }
}
