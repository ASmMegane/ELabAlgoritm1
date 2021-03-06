#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

void CalculateDistanceBetweenWords(int & minDistans, int & maxDistans, const std::string & text, const std::string & word1, const std::string & word2)
{

	//находим все позиции 1 слова
	std::vector<int> posesFirstWord;
	for (int i = text.find(word1, 0) ; i != std::string::npos; i = text.find(word1, i + 1))
		posesFirstWord.push_back(i);
	
	//находим все позиции 2 слова
	std::vector<int> posesSecondWord;
	for (int i = text.find(word2, 0); i != std::string::npos; i = text.find(word2, i + 1))
		posesSecondWord.push_back(i);

	int minDis = 0;
	int maxDis = 0;

	//проходим по всем позициям слов в векторах
	for (int posFirste : posesFirstWord)
	{
		for (int posSecond : posesSecondWord)
		{
			//создаем подстроку от 1 слова до 2, или же от 2 до 1, взависимости у кого позиция меньше
			std::string subStr;
			if (posFirste > posSecond)
			{
				subStr = text.substr(posSecond, posFirste - posSecond);;
			}
			else
			{
				subStr = text.substr(posFirste, posSecond - posFirste);
			}	
			//---------------------------------
			
			//считаем кол-во пробелов и вычитаем 1, получаем кол-во слов между
			int dis = std::count(subStr.begin(), subStr.end(), ' ') - 1;
			
			//сравниваем результат уже с имеющимися, выбираем нужный
			if (dis < minDis || minDis == 0)
			{
				minDis = dis;
			}
			if (dis > maxDis)
			{
				maxDis = dis;
			}
		}
	}
	//сохроняем и возвращаем полученый результат
	minDistans = minDis;
	maxDistans = maxDis;
}



int main()
{
	std::string text = "За четверть часа до захождения солнца, весной, вы входите в рощу с ружьём, без собаки. Вы отыскиваете себе место где-нибудь подле опушки, оглядываетесь, осматриваете пистон, перемигиваетесь с товарищем. Четверть часа прошло. Солнце село, но в лесу ещё светло; воздух чист и прозрачен";
	std::string wordFirst = "часа";
	std::string wordSecond = "вы";
	int minDist;
	int maxDist;	
	CalculateDistanceBetweenWords(minDist, maxDist, text, wordFirst, wordSecond);
	std::cout << maxDist << std::endl;
	std::cout << minDist << std::endl;
}

//сложность алгоритма O(n2) — квадратичная сложность
//затраченное время 4 часа
