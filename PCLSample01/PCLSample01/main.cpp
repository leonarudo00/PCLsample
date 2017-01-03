// C��min,max�}�N���𖳌��ɂ���
#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <pcl\visualization\cloud_viewer.h>
#include <pcl\io\vtk_lib_io.h>

// obj�f�[�^���擾
const char filename[] = "bunny.obj";

void main()
{
	try{
		// obj�t�@�C����ǂݍ���
		pcl::PolygonMesh::Ptr mesh( new pcl::PolygonMesh() );
		pcl::PointCloud<pcl::PointXYZ>::Ptr obj_pcd( new pcl::PointCloud<pcl::PointXYZ>() );
		if ( pcl::io::loadPolygonFileOBJ( filename, *mesh ) != -1 ){
			pcl::fromPCLPointCloud2( mesh->cloud, *obj_pcd );
		}

		// �E�B���h�E�̍쐬
		pcl::visualization::PCLVisualizer viewer( "Point Cloud Viewer" );

		// PointCloud��ǉ�
		viewer.addPointCloud( obj_pcd );

		// �E�B���h�E�����Ă��Ȃ��ԑ���
		while ( !viewer.wasStopped() ) {
			// �X�N���[�����X�V
			viewer.spinOnce();

			// ESCAPE�L�[�������ꂽ��I��
			if ( GetKeyState( VK_ESCAPE ) < 0 ){
				break;
			}
		}
	}
	catch ( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}
}