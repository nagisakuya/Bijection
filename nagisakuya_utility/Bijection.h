#pragma once
#include <map>
#include <initializer_list>
#include <utility>

//Bijection = �S�P��
//key��value�����񕪖؃N���X(map?)���p�ӂ��āAkey�ɒl�Avalue�ɑΉ�����l��key�ւ̎Q�Ƃ��i�[���邱�ƂŁA���݂ɍ��������o����c�͂��B
//���݂Ƀ|�C���^�����������R���e�i�͍쐬�s�ł��邱�Ƃ�����w
//map<int,map<int,map<int,map<int,map<int,.....>*>*>*>*> first:
//void* ������������ł����B


namespace nagisakuya {
	namespace Bijection {
		template <class F, class S>
		class bijection
		{
		private:
			typename std::map<F,const void*> f;
			typename std::map<S,const void*> s;
		public:
			bijection(){};
			bijection(std::initializer_list<typename std::pair < F, S >> input) {
				for (auto i : input)
				{
					add(i);
				}
			}
			void add(typename std::pair<F, S> input) {
				emplace(input.first, input.second);
			}
			void emplace(F first, S second) {
				f[first];
				s[second] = &(f.find(first)->first);
				f[first] = &(s.find(second)->first);
			}
			F find_at(S input) {
				return *(F*)f.at(input);
			}
			S find_at(F input) {
				return *(S*)s.at(input);
			}
			bijection operator =(std::initializer_list<typename std::pair < F, S >> input) {
				return bijection(input);
			}
		};
	}
}

