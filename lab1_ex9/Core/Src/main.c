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
void clearAllClock();
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
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
  int counter = -1;
  clearAllClock();
  setNumberOnClock(0);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  switch(counter) {
		  case 0: //LED 1 off, LED 2 on
			  clearNumberOnClock(0);
			  setNumberOnClock(1);
			  break;
		  case 1: //LED 2 off, LED 3 on
			  clearNumberOnClock(1);
			  setNumberOnClock(2);
			  break;
		  case 2: //LED 3 off, LED 4 on
			  clearNumberOnClock(2);
			  setNumberOnClock(3);
			  break;
		  case 3: //LED 4 off, LED 5 on
			  clearNumberOnClock(3);
			  setNumberOnClock(4);
			  break;
		  case 4: //LED 5 off, LED 6 on
			  clearNumberOnClock(4);
			  setNumberOnClock(5);
			  break;
		  case 5: //LED 6 off, LED 7 on
			  clearNumberOnClock(5);
			  setNumberOnClock(6);
			  break;
		  case 6: //LED 7 off, LED 8 on
			  clearNumberOnClock(6);
			  setNumberOnClock(7);
			  break;
		  case 7: //LED 8 off, LED 9 on
			  clearNumberOnClock(7);
			  setNumberOnClock(8);
			  break;
		  case 8: //LED 9 off, LED 10 on
			  clearNumberOnClock(8);
			  setNumberOnClock(9);
			  break;
		  case 9: //LED 10 off, LED 11 on
			  clearNumberOnClock(9);
			  setNumberOnClock(10);
			  break;
		  case 10: //LED 11 off, LED 12 on
			  clearNumberOnClock(10);
			  setNumberOnClock(11);
			  break;
		  case 11: //LED 12 off, LED 1 on
			  clearNumberOnClock(11);
			  setNumberOnClock(0);
			  break;
	  }
	  counter++;
	  if(counter >= 12)
		  counter = 0; //Repeat the above effect endlessly.
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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin|L4_Pin
                          |L5_Pin|L6_Pin|L7_Pin|L8_Pin
                          |L9_Pin|L10_Pin|L11_Pin|L12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : L1_Pin L2_Pin L3_Pin L4_Pin
                           L5_Pin L6_Pin L7_Pin L8_Pin
                           L9_Pin L10_Pin L11_Pin L12_Pin */
  GPIO_InitStruct.Pin = L1_Pin|L2_Pin|L3_Pin|L4_Pin
                          |L5_Pin|L6_Pin|L7_Pin|L8_Pin
                          |L9_Pin|L10_Pin|L11_Pin|L12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void clearAllClock() {
	HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_SET);
}

void setNumberOnClock(int num) {
	switch(num) {
	case 0:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_RESET);
		break;
	}
}

void clearNumberOnClock(int num) {
	switch(num) {
	case 0:
		HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
		break;
	case 5:
		HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
		break;
	case 6:
		HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
		break;
	case 7:
		HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
		break;
	case 9:
		HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
		break;
	case 10:
		HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
		break;
	case 11:
		HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_SET);
		break;
	}
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
