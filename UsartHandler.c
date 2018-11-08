#include "UsartHandler.h"

void UsartInit()
{
	
#define  USART_ISR_PE                        ((uint32_t)0x00000001U)            /*!< Parity Error */
#define  USART_ISR_FE                        ((uint32_t)0x00000002U)            /*!< Framing Error */
#define  USART_ISR_NE                        ((uint32_t)0x00000004U)            /*!< Noise detected Flag */
#define  USART_ISR_ORE                       ((uint32_t)0x00000008U)            /*!< OverRun Error */
#define  USART_ISR_IDLE                      ((uint32_t)0x00000010U)            /*!< IDLE line detected */
#define  USART_ISR_RXNE                      ((uint32_t)0x00000020U)            /*!< Read Data Register Not Empty */
#define  USART_ISR_TC                        ((uint32_t)0x00000040U)            /*!< Transmission Complete */
#define  USART_ISR_TXE                       ((uint32_t)0x00000080U)            /*!< Transmit Data Register Empty */
#define  USART_ISR_LBDF                      ((uint32_t)0x00000100U)            /*!< LIN Break Detection Flag */
#define  USART_ISR_CTSIF                     ((uint32_t)0x00000200U)            /*!< CTS interrupt flag */
#define  USART_ISR_CTS                       ((uint32_t)0x00000400U)            /*!< CTS flag */
#define  USART_ISR_RTOF                      ((uint32_t)0x00000800U)            /*!< Receiver Time Out */
#define  USART_ISR_EOBF                      ((uint32_t)0x00001000U)            /*!< End Of Block Flag */
#define  USART_ISR_ABRE                      ((uint32_t)0x00004000U)            /*!< Auto-Baud Rate Error */
#define  USART_ISR_ABRF                      ((uint32_t)0x00008000U)            /*!< Auto-Baud Rate Flag */
#define  USART_ISR_BUSY                      ((uint32_t)0x00010000U)            /*!< Busy Flag */
#define  USART_ISR_CMF                       ((uint32_t)0x00020000U)            /*!< Character Match Flag */
#define  USART_ISR_SBKF                      ((uint32_t)0x00040000U)            /*!< Send Break Flag */
#define  USART_ISR_RWU                       ((uint32_t)0x00080000U)            /*!< Receive Wake Up from mute mode Flag */
#define  USART_ISR_WUF                       ((uint32_t)0x00100000U)            /*!< Wake Up from stop mode Flag */
#define  USART_ISR_TEACK                     ((uint32_t)0x00200000U)            /*!< Transmit Enable Acknowledge Flag */
#define  USART_ISR_REACK                     ((uint32_t)0x00400000U)            /*!< Receive Enable Acknowledge Flag */
	
	
	/*******************  Bit definition for USART_RDR register  ******************/
#define  USART_RDR_RDR                       ((uint16_t)0x01FFU)                /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define  USART_TDR_TDR                       ((uint16_t)0x01FFU)                /*!< TDR[8:0] bits (Transmit Data value) */

USART2->CR1 &= ~USART_CR1_UE; // dissable usart
USART2->CR1 &= ~USART_CR1_M; // set to be 8 bit message
USART2->CR2 &= ~USART_CR2_STOP; //set to be 1 stop bit
USART2->CR1 &= ~USART_CR1_PCE; //set parity
USART2->CR1 &= ~USART_CR1_OVER8; // set oversampling
USART2->BRR =  0x208D; // set baud rate
USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE);//enable transmission and reception
USART2->CR1 |= USART_CR1_UE;?/enable usart
while ((USART2->ISR & USART_ISR_TEACK) == 0);
	{
		
	}
while ((USART2->ISR & USART_ISR_REACK) == 0);
	{
		
	}
}

void UsartWrite(unit8_t *letter)
{
	
}

void UsartRead(unit8_t *thebuffer)
{
	
	
}







