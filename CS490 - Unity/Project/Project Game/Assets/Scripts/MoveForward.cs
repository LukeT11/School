using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveForward : MonoBehaviour
{
    private GameManager gameManager;
    private float speed = 10;
    // Start is called before the first frame update
    void Start()
    {
        gameManager = GameObject.Find("Game Manager").GetComponent<GameManager>();
    }

    // Update is called once per frame
    void Update()
    {
        if (gameManager.isGameActive)
        {
            if (gameObject.CompareTag("Fish") || gameObject.CompareTag("Krill") || gameObject.CompareTag("Squid"))
            {
                transform.Translate(Vector3.forward * speed * Time.deltaTime);
            }

            if (gameObject.CompareTag("Boulder") || gameObject.CompareTag("Glacier") || gameObject.CompareTag("Ridge") || gameObject.CompareTag("Coin") || gameObject.CompareTag("Tree"))
            {
                transform.Translate(Vector3.back * speed * Time.deltaTime);
            }

            if (gameObject.CompareTag("Boulder"))
            {
                transform.Translate(Vector3.left * speed * Time.deltaTime);
            }
        }
    }
}
