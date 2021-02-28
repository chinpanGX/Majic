/*----------------------------------------------
	
	[Singleton.h]
	Author : 出合翔太

	[説明]
	シングルトンクラスのテンプレート

-----------------------------------------------*/
#pragma once

template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}
protected:
	Singleton() {}
	virtual ~Singleton() {}
private:
	// コピーコンストラクタ、代入の禁止
	void operator=(const Singleton&) = delete;
	Singleton(const Singleton&) = delete;
};

