#pragma once

class GamePlayer {
private:
	static const int NumTurns = 5; // ��������ʽ��in-class ��ֵ�趨��ֻ�����������������
	int scores[NumTurns]; // ʹ�øó���
};


class CostEstimate {
private:
	static const double FudgeFactor; // ��������ʽ
};

class GamePlayer2 {
private:
	enum { NumTurns = 5 }; // the enum hack
	int scores[NumTurns];
};
