/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG1(int num);
void display7SEG2(int num);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  //2 variables for 2 traffic lights
  int count1 = 0;
  int count2 = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  // led 7 segments: red from 5 to 0, green from 3 to 1, yellow from 2 to 0
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
	  // display traffic light 1 and led 7 segments 1
	  if(count1 < 6) { //red 1 first
		  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		  display7SEG1(5-count1);
	  }
	  else {
		  if(count1 < 9) { //then green 1
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			  display7SEG1(9-count1);
		  }
		  else { //and finally yellow 1
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			  display7SEG1(11-count1);
		  }
	  }
	  count1++;
	  if(count1 >= 12)
		  count1 = 0; //back to red 1

	  // display traffic light 2 and led 7 segments 2
	  if(count2 < 3) { // green 2 first
		  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
		  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		  display7SEG2(3-count2);
	  }
	  else {
		  if(count2 < 6) { //then yellow 2
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
			  display7SEG2(5-count2);
		  }
		  else { //and finally red 2
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
			  display7SEG2(11-count2);
		  }
	  }
	  count2++;
	  if(count2 >= 12)
		  count2 = 0; //back to green 2

	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG1_A_Pin|SEG1_B_Pin|SEG1_C_Pin|SEG2_D_Pin
                          |SEG2_E_Pin|SEG2_G_Pin|SEG2_F_Pin|SEG1_D_Pin
                          |SEG1_E_Pin|SEG1_F_Pin|SEG1_G_Pin|SEG2_A_Pin
                          |SEG2_B_Pin|SEG2_C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED1_Pin YELLOW1_Pin GREEN1_Pin RED2_Pin
                           YELLOW2_Pin GREEN2_Pin */
  GPIO_InitStruct.Pin = RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
                          |YELLOW2_Pin|GREEN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG1_A_Pin SEG1_B_Pin SEG1_C_Pin SEG2_D_Pin
                           SEG2_E_Pin SEG2_G_Pin SEG2_F_Pin SEG1_D_Pin
                           SEG1_E_Pin SEG1_F_Pin SEG1_G_Pin SEG2_A_Pin
                           SEG2_B_Pin SEG2_C_Pin */
  GPIO_InitStruct.Pin = SEG1_A_Pin|SEG1_B_Pin|SEG1_C_Pin|SEG2_D_Pin
                          |SEG2_E_Pin|SEG2_G_Pin|SEG2_F_Pin|SEG1_D_Pin
                          |SEG1_E_Pin|SEG1_F_Pin|SEG1_G_Pin|SEG2_A_Pin
                          |SEG2_B_Pin|SEG2_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void display7SEG1(int num) {
	// list of numeric states of 7 segments 1
	int dis_arr[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
	int bit_var, var2;

	var2 = ~dis_arr[num]; // index starts from 0
	bit_var = var2 & 0x01; // keeping LSB and masking other bits
	HAL_GPIO_WritePin(GPIOB, SEG1_A_Pin, bit_var);

	bit_var = (var2>>1) & 0x01; // right shift by 1
	HAL_GPIO_WritePin(GPIOB, SEG1_B_Pin, bit_var);

	bit_var = (var2>>2) & 0x01; // original variable right shift by 2 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG1_C_Pin, bit_var);

	bit_var = (var2>>3) & 0x01; // original variable right shift by 3 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG1_D_Pin, bit_var);

	bit_var = (var2>>4) & 0x01; // original variable right shift by 4 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG1_E_Pin, bit_var);

	bit_var = (var2>>5) & 0x01; // original variable right shift by 5 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG1_F_Pin, bit_var);

	bit_var = (var2>>6) & 0x01; // original variable right shift by 6 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG1_G_Pin, bit_var);
}

////-------------------------------////

void display7SEG2(int num) {
	// list of numeric states of 7 segments 2
	int dis_arr[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
	int bit_var, var2;

	var2 = ~dis_arr[num]; // index starts from 0
	bit_var = var2 & 0x01; // keeping LSB and masking other bits
	HAL_GPIO_WritePin(GPIOB, SEG2_A_Pin, bit_var);

	bit_var = (var2>>1) & 0x01; // right shift by 1
	HAL_GPIO_WritePin(GPIOB, SEG2_B_Pin, bit_var);

	bit_var = (var2>>2) & 0x01; // original variable right shift by 2 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG2_C_Pin, bit_var);

	bit_var = (var2>>3) & 0x01; // original variable right shift by 3 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG2_D_Pin, bit_var);

	bit_var = (var2>>4) & 0x01; // original variable right shift by 4 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG2_E_Pin, bit_var);

	bit_var = (var2>>5) & 0x01; // original variable right shift by 5 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG2_F_Pin, bit_var);

	bit_var = (var2>>6) & 0x01; // original variable right shift by 6 and then masking
	HAL_GPIO_WritePin(GPIOB, SEG2_G_Pin, bit_var);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
