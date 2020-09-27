#pragma once
#include <map>
#include <initializer_list>
#include <string>

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
			typename std::map<F,const void*> first_element;
			typename std::map<S,const void*> second_element;
		public:
			bijection(){};
			bijection(std::initializer_list<typename std::pair < F, S >> input) {
				add(input);
			}
			void add(std::initializer_list<typename std::pair < F, S >> input) {
				for (auto i : input)
				{
					emplace(i.first, i.second);
				}
			}
			void add(typename std::pair<F, S> input) {
				emplace(input.first, input.second);
			}
			void emplace(F first, S second) {
				first_element[first];
				second_element[second] = &(first_element.find(first)->first);
				first_element[first] = &(second_element.find(second)->first);
			}
			F at_stof(S second) {
				return *(F*)(second_element.at(second));
			}
			S at_ftos(F first) {
				return *((S*)first_element.at(first));
			}
			bijection operator =(std::initializer_list<typename std::pair < F, S >> input) {
				return bijection(input);
			}
		};
	}
}

