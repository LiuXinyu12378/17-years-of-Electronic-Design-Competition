#include "adc.h"


//��ʼ��ADC															   
void  Adc_Init(void)
{    
  GPIO_InitTypeDef  GPIO_InitStructure;
//	ADC_CommonInitTypeDef ADC_CommonInitStructure;
//	ADC_InitTypeDef       ADC_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);//ʹ��GPIOAʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);//ʹ��GPIOAʱ��
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC1ʱ��

  //�ȳ�ʼ��ADC1ͨ��5 IO��
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//PA5 ͨ��5
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//����������
//  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��  
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5
								|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;//PA5 ͨ��5
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ�� 
	
	GPIO_SetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ�� 
//  GPIO_SetBits(GPIOF,GPIO_Pin_1);
}	
			  
//���ADCֵ
//ch: @ref ADC_channels 
//ͨ��ֵ 0~16ȡֵ��ΧΪ��ADC_Channel_0~ADC_Channel_16
//����ֵ:ת�����
u16 Get_Adc(u8 ch)   
{
	  	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,480������,��߲���ʱ�������߾�ȷ��			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1������ת����������	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������

	return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת�����
}

