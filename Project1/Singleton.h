/*----------------------------------------------
	
	[Singleton.h]
	Author : �o���đ�

	[����]
	�V���O���g���N���X�̃e���v���[�g

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
	// �R�s�[�R���X�g���N�^�A����̋֎~
	void operator=(const Singleton&) = delete;
	Singleton(const Singleton&) = delete;
};

