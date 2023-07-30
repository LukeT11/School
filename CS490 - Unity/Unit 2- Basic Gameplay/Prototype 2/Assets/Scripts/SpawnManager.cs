using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnManager : MonoBehaviour
{
    public GameObject[] animalPrefabs;
    private float spawnRangeX = 20;
    private float spawnPosZ = 20;
    private float startDelay = 2.0f;
    public float spawnInterval = 1.5f

    // Start is called before the first frame update
    void Start()
    {
        //Calls Function SpawnRandomAnimal with startDelay and then at constant rate
        InvokeRepeating("SpawnRandomAnimal", startDelay, spawnInterval);
    }

    // Update is called once per frame
    void Update()
    {
        spawnInterval = Random.Range(2, 4);
    }

    //SpawnRandomAnimal randomaly spawns an object (animal in this case)
    void SpawnRandomAnimal()
    {
        //Random number within index range for a random object (animal)
        int animalIndex = Random.Range(0, animalPrefabs.Length);

        //Random animal index and spawn location
        Vector3 spawnPos = new Vector3(Random.Range(-spawnRangeX, spawnRangeX), 0, spawnPosZ);

        //Random spawn at random location
        Instantiate(animalPrefabs[animalIndex], spawnPos, animalPrefabs[animalIndex].transform.rotation);
    }
}
