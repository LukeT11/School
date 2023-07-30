using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public TextMeshProUGUI scoreText;
    public TextMeshProUGUI gameOverText;
    public TextMeshProUGUI distanceText;
    public Button startButton;
    public Button restartButton;
    public GameObject titleScreen;
    public bool isGameActive;
    public bool restartGame;
    private int score;
    private int distanceTracked;

    // Start is called before the first frame update
    void Start()
    {
        startButton.onClick.AddListener(StartGame);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void StartGame()
    {
        isGameActive = true;
        restartGame = false;
        score = 0;

        UpdateScore(0);
        UpdateDistance(0);

        titleScreen.gameObject.SetActive(false);
    }

    public void RestartGame()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    public void GameOver()
    {
        restartButton.gameObject.SetActive(true);
        gameOverText.gameObject.SetActive(true);
        isGameActive = false;
    }

    public void UpdateScore(int scoreToAdd)
    {
        scoreText.gameObject.SetActive(true);
        score += scoreToAdd;
        scoreText.text = "     Score: " + score;
    }

    public void UpdateDistance(int totalDistance)
    {
        distanceText.gameObject.SetActive(true);
        distanceTracked = totalDistance;
        distanceText.text = "Distance: " + distanceTracked + "m";
    }
}
