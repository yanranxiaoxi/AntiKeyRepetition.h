/*
 * @title	AntiKeyRepetition.cpp
 * @description	无延迟阻止按键重复触发
 * 
 * @author	XiaoXi
 * @email	admin@soraharu.com
 * 
 * @param	byte	p		按键物理地址（引脚）
 * @param	boolean	state	当前按键状态
 * @param	boolean	old		前次按键状态
 * @param	boolean	access	按键操作合法为“1”，非法为“0”
 * 
 * @date	2021-09-30 21:25
 */

#include "AntiKeyRepetition.h"

#include "Arduino.h"

AntiKeyRepetition::AntiKeyRepetition(byte pin):p(pin) {
	pinMode(p, INPUT_PULLUP);
}

bool AntiKeyRepetition::getAccessState() {
	state = digitalRead(p);		// 读取按键状态（低有效）
	if(state == 0) {			// 如果 按键被按下
		if(old == 1) {			// 并且 前次按键状态为未被按下
			access = 1;			// 则 按键操作合法
			old = 0;			// 且 将前次按键状态设置为已被按下
		}						// 如果 按键被按下，并且前次按键状态为已被按下，则不执行任何操作
	} else {					// 如果 按键没有被按下
		old = 1;				// 则 将前次按键状态设置为未被按下
	}
	return access;
}

void AntiKeyRepetition::delAccess() {
	access = 0;
}
