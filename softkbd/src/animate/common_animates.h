/*
** This file is a part of mg-demos package.
**
** Copyright (C) 2008 ~ 2019 FMSoft (http://www.fmsoft.cn).
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef COMMON_ANIMATES_H
#define COMMON_ANIMATES_H

#include "p-code.h"
#include "animate.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

void SetInterval(int interval_ms);

typedef struct _ANIMATE_OPS{
	DRAW_ANIMATE draw_animate;
	void (*draw_bkgnd)(HDC hdc, const RECT* rtbk, void *param);
	void (*on_finished)(ANIMATE_SENCE * as);
	void (*before_draw_one_frame)(ANIMATE_SENCE* as);
	void (*end_draw_one_frame)(ANIMATE_SENCE* as);
}ANIMATE_OPS;

typedef struct _PUSH_PULL_OBJ{
	void *img;
	int x_begin;
	int y_begin;
	int x_end;
	int y_end;
}PUSH_PULL_OBJ;

void RunPushPullAnimate(HDC hdc, const RECT *rt, PUSH_PULL_OBJ* objs, int obj_cnt, ANIMATE_OPS *ops, int frame_num, void* user_param);

void RunPushPullBitmapAnimate(HDC hdc, const RECT *rt, PBITMAP bmpPush, PBITMAP bmpPull, int frame_num, BOOL left_to_right);

void RunPushPullWindowAnimate(const RECT *rt, HWND hwndPush, HWND hwndPull, int frame_num, BOOL left_to_right);


void RunPinAnimate(HDC hdc, PBITMAP bmpbk, PBITMAP bmpPin, int x, int y, int x_begin, int y_begin, int x_end, int y_end);

void RunJumpWindow(HWND hwnd, int x_begin, int y_begin, int x_end, int y_end, int w, int h, void (*on_finished)(ANIMATE_SENCE* as), void *param);

void StartAlphaAnimate (int interval, int all_times, HDC hdc, 
        const BITMAP* bitmap, const RECT* rc, int start_alpha, int end_alpha);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* COMMON_ANIMATES_H */

