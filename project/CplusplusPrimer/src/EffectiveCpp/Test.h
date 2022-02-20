#pragma once

class GamePlayer {
private:
	static const int NumTurns = 5; // 常量声明式，in-class 初值设定，只允许对整数常量进行
	int scores[NumTurns]; // 使用该常量
};


class CostEstimate {
private:
	static const double FudgeFactor; // 常量声明式
};

class GamePlayer2 {
private:
	enum { NumTurns = 5 }; // the enum hack
	int scores[NumTurns];
};
