#pragma once
#include <map>
#include <initializer_list>

//Bijection = �S�P��
//key��value�����񕪖؃N���X(map?)���p�ӂ��āAkey�ɒl�Avalue�ɑΉ�����l��key�ւ̎Q�Ƃ��i�[���邱�ƂŁA���݂ɍ��������o����c�͂��B
//���݂Ƀ|�C���^�����������R���e�i�͍쐬�s�ł��邱�Ƃ�����w
//pair<int,pair<int,pair<int,pair<int,pair<int,.....>*>*>*>*> first:
//void* ������������ł����B


namespace nagisakuya {
	namespace Bijection {
		template <class F, class S>
		class bijection
		{
		private:
			std::map<F, typename std::map<S, void*>::iterator> f;
			std::map<S, typename std::map<F, void*>::iterator> s;
		public:
			bijection(std::initializer_list<std::pair < F, S >>input = {});
			void add(std::pair<F, S> input);
			void emplace(F first, S second);
			size_t size();
			F find_first(S input);
			S find_second(F input);
		};
	}
}

