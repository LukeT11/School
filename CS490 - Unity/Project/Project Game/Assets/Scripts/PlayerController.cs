using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private GameManager gameManager;
    public float horizontalInput;
    public float jumpForce = 275.0f;
    public Rigidbody playerRB;
    public float playerSpeedNormal = 15.0f;
    public float playerSpeed;
    public float xRange = 3.5f;
    public float xSlowDown = 3.48f;
    public bool onGround = true;
    public float gravityModifier = 2.0f;
    public int fishScore = 500;
    public int krillScore = 1000;
    public int squidScore = 1500;
    public int coinScore = 10;

    // Start is called before the first frame update
    void Start()
    {
        gameManager = GameObject.Find("Game Manager").GetComponent<GameManager>();
        playerRB = GetComponent<Rigidbody>();
        playerSpeed = playerSpeedNormal;
        Physics.gravity *= gravityModifier;
    }

    // Update is called once per frame
    void Update()
    {
        if (gameManager.isGameActive)
        {
            userInput();
            boundaries();
        }
    }

    private void userInput()
    {
        if (Input.GetKeyDown(KeyCode.Space) && onGround)
        {
            playerRB.AddForce(Vector3.up * jumpForce, ForceMode.Impulse);
            onGround = false;
        }

        horizontalInput = Input.GetAxis("Horizontal");
        transform.Translate(Vector3.right * horizontalInput * Time.deltaTime * playerSpeed);
    }

    private void boundaries()
    {
        if (transform.position.x < -xRange)
        {
            transform.position = new Vector3(-xRange, transform.position.y, transform.position.z);
        }

        if (transform.position.x > xRange)
        {
            transform.position = new Vector3(xRange, transform.position.y, transform.position.z);
        }



        if (transform.position.x < -xSlowDown || transform.position.x > xSlowDown)
        {
            playerSpeed = 1.0f;
        }



        if (transform.position.x > -xSlowDown && transform.position.x < xSlowDown)
        {
            playerSpeed = playerSpeedNormal;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Ground"))
        {
            onGround = true;
        }

        if (collision.gameObject.CompareTag("Glacier") || collision.gameObject.CompareTag("Ridge") || collision.gameObject.CompareTag("Snow Tree") || collision.gameObject.CompareTag("Boulder"))
        {
            Debug.Log("Game Over");
            gameManager.GameOver();
        }
    }


    private void OnTriggerEnter(Collider other)
    {
       // Debug.Log("Collided with: " + other.gameObject.name);

        if (other.CompareTag("Fish"))
        {
            Destroy(other.gameObject);
            gameManager.UpdateScore(fishScore);
        }

        if (other.CompareTag("Krill"))
        {
            Destroy(other.gameObject);
            gameManager.UpdateScore(krillScore);
        }

        if (other.CompareTag("Squid"))
        {
            Destroy(other.gameObject);
            gameManager.UpdateScore(squidScore);
        }

        if (other.CompareTag("Coin"))
        {
            Destroy(other.gameObject);
            gameManager.UpdateScore(coinScore);
        }
    }
}
