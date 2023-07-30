using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveGround : MonoBehaviour
{
    private GameManager gameManager;
    private int speed = 10;
    private Vector3 startPos;
    private float repeatNum;
    public int totalDistance;

    // Start is called before the first frame update
    void Start()
    {
        gameManager = GameObject.Find("Game Manager").GetComponent<GameManager>();
        startPos = transform.position;
        repeatNum = (GetComponent<BoxCollider>().size.z / 2);
        totalDistance = 0;
    }

    // Update is called once per frame
    void Update()
    {
        if (gameManager.isGameActive)
        {
            RecordDistance();

            transform.Translate(Vector3.back * Time.deltaTime * speed);

            if (transform.position.z < startPos.z - repeatNum)
            {
                transform.position = startPos;
            }
        }

    }

    public void RecordDistance()
    {
        totalDistance += 1;
        gameManager.UpdateDistance(totalDistance);
    }
}
