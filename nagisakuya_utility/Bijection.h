#pragma once
#include <map>
#include <initializer_list>
#include <string>

//Bijection = 全単射
//keyとvalueを持つ二分木クラス(map?)を二つ用意して、keyに値、valueに対応する値のkeyへの参照を格納することで、相互に高速検索出来る…はず。
//相互にポインタを持ち合うコンテナは作成不可であることが判明w
//map<int,map<int,map<int,map<int,map<int,.....>*>*>*>*> first:
//void* を持たせたらできた。


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

