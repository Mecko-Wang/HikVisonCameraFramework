// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HOPERATOR_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HOPERATOR_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef HOPERATOR_EXPORTS
#define HOPERATOR_API __declspec(dllexport)
#else
#define HOPERATOR_API __declspec(dllimport)
#endif

#include "halconcpp.h"       
using namespace HalconCpp;

// �����Ǵ� HOperator.dll ������
class HOPERATOR_API CHOperator {
public:
	CHOperator(void);
	// TODO:  �ڴ�������ķ�����
	void find_material(HObject ho_Image, HObject *ho_SelectContour, HTuple hv_ModelID,
		HTuple hv_MinScale, HTuple hv_MaxScale, HTuple hv_MinScore, 
		HTuple *hv_Scale, HTuple *hv_Score);
	void find_material_circle(HObject ho_Image, HTuple hv_ModelID, HTuple hv_ScaleMin,
		HTuple hv_ScaleMax, HTuple hv_MinScore, HTuple *hv_Row, HTuple *hv_Column, HTuple *hv_Radius,
		HTuple *hv_Scale, HTuple *hv_Score);
};

extern HOPERATOR_API int nHOperator;

HOPERATOR_API int fnHOperator(void);
