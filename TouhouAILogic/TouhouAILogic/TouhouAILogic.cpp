// これは メイン DLL ファイルです。

#include "stdafx.h"

#include "TouhouAILogic.h"
#include "KeyManage.h"

String^ TouhouAILogic::Class1::GetString()
{
	KeyManage::Instance().SendUp();

	return "te222st";

}