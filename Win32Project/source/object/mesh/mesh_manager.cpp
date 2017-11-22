//=============================================================================
//
// [mesh_manager.h]
// Author : shota fukuoka
//
//=============================================================================
#include "mesh_manager.h"
#include "mesh.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

///////////////////////////////////////////////////////////////////////////////
//コンストラクタ
///////////////////////////////////////////////////////////////////////////////
MeshManager::MeshManager()
{
	;
}

///////////////////////////////////////////////////////////////////////////////
//デストラクタ
///////////////////////////////////////////////////////////////////////////////
MeshManager::~MeshManager()
{
	;
}

///////////////////////////////////////////////////////////////////////////////
//追加
///////////////////////////////////////////////////////////////////////////////
void MeshManager::AddMesh(Mesh* mesh)
{
	if (mesh == NULL) { return; }
	m_list.push_back(mesh);
}

///////////////////////////////////////////////////////////////////////////////
//削除
///////////////////////////////////////////////////////////////////////////////
void MeshManager::DeleteMesh(const Mesh* mesh)
{
	for (auto ite = m_list.begin(); ite != m_list.end(); ++ite)
	{
		if ((*ite) != mesh) { continue; }
		m_list.erase(ite);
		return;
	}
}

///////////////////////////////////////////////////////////////////////////////
//全更新
///////////////////////////////////////////////////////////////////////////////
void MeshManager::UpdateAll(void)
{
	for (auto ite = m_list.begin(); ite != m_list.end(); ++ite)
	{
		if ((*ite) == NULL) { continue; }
		(*ite)->Update();
	}
}

///////////////////////////////////////////////////////////////////////////////
//全削除
///////////////////////////////////////////////////////////////////////////////
void MeshManager::ReleaseAll(void)
{
	for (auto ite = m_list.begin(); ite != m_list.end(); ++ite)
	{
		if ((*ite) == NULL) { continue; }
		(*ite)->Release();
	}
}

