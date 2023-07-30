using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControllerX : MonoBehaviour
{
    public GameObject dogPrefab;
    private float timePassed;
    private float minTime = 0.5f;

    // Update is called once per frame
    void Update()
    {
        //Keeps track of time after a dog is sent
        timePassed += Time.deltaTime;

        // On spacebar press, send dog
        if (Input.GetKeyDown(KeyCode.Space) && timePassed > minTime)
        {
            Instantiate(dogPrefab, transform.position, dogPrefab.transform.rotation);
            timePassed = 0;
        }
    }
}
