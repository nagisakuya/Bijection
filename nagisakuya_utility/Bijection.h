#pragma once
#include <map>
#include <initializer_list>
#include <utility>

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

