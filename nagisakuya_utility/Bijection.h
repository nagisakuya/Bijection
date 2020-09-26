#pragma once
#include <map>
#include <initializer_list>

//Bijection = 全単射
//keyとvalueを持つ二分木クラス(map?)を二つ用意して、keyに値、valueに対応する値のkeyへの参照を格納することで、相互に高速検索出来る…はず。
//相互にポインタを持ち合うコンテナは作成不可であることが判明w
//pair<int,pair<int,pair<int,pair<int,pair<int,.....>*>*>*>*> first:
//void* を持たせたらできた。


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

