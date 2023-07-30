using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CapsuleSimulation : MonoBehaviour
{
    public GameObject[] objective;
    public int current = 0;
    public float speed = 5;

    
  
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Invoke("MoveUp", 0f);
        Invoke("LandDown", 5f);
    }

    void MoveUp()
    {
        if (transform.position.y <= 10 && transform.position.x == 0 && transform.position.z == 0)
        {
            transform.position = (Vector3.up * speed * Time.deltaTime);
        }
    }
    void MoveRight()
    {

    }
    void MoveLeft()
    {

    }
    void MoveDown()
    {

    }
    void LandDown()
    {
        if (Vector3.Distance(objective[current].transform.position, transform.position) < 1)
        {
            current++;
        }

        transform.position = Vector3.MoveTowards(transform.position, objective[current].transform.position + new Vector3(0 ,1 ,0), Time.deltaTime * speed);
    }
}
