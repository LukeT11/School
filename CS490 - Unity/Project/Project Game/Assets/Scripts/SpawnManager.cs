using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnManager : MonoBehaviour
{
    private GameManager gameManager;
    public GameObject[] obstacles;
    public GameObject[] itemPoints;
    public GameObject ramp;
    public GameObject coin;
    public float xRange = 3.4f;
    public float zRange = 70.0f;
    public float spawnRate1 = 5.0f;
    public float startDelay = 1.0f;

    // Start is called before the first frame update
    void Start()
    {
        gameManager = GameObject.Find("Game Manager").GetComponent<GameManager>();
        Invoke("SpawnRandomItem", startDelay);
        Invoke("SpawnRandomObstacle", startDelay);
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    public void SpawnRandomItem()
    {
        if (gameManager.isGameActive)
        {
            int itemsIndex = Random.Range(0, itemPoints.Length);
            Instantiate(itemPoints[itemsIndex], GenSpawnPosItem(), itemPoints[itemsIndex].transform.rotation);
        }

        float randomSpawnRate = 1;
        Invoke("SpawnRandomItem", randomSpawnRate);
    }
    public void SpawnRandomObstacle()
    {
        if (gameManager.isGameActive)
        {
            int obstacleIndex = Random.Range(0, obstacles.Length);
            Instantiate(obstacles[obstacleIndex], GenSpawnPosObject(), obstacles[obstacleIndex].transform.rotation);
        }

        float randomSpawnRate = 1;
        Invoke("SpawnRandomObstacle", randomSpawnRate);
}

    Vector3 GenSpawnPosItem()
    {
        return new Vector3(Random.Range(-xRange, xRange), (float)0.35, zRange);
    }

    Vector3 GenSpawnPosObject()
    {
        return new Vector3(Random.Range(-xRange, xRange), (float)1.2, zRange);
    }

    public void SpawnObjects()
    {
        
    }
}
