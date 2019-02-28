// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 HOPERATOR_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// HOPERATOR_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef HOPERATOR_EXPORTS
#define HOPERATOR_API __declspec(dllexport)
#else
#define HOPERATOR_API __declspec(dllimport)
#endif

#include "halconcpp.h"       
using namespace HalconCpp;

// 此类是从 HOperator.dll 导出的
class HOPERATOR_API CHOperator {
public:
	CHOperator(void);
	// TODO:  在此添加您的方法。
	void find_material(HObject ho_Image, HObject *ho_SelectContour, HTuple hv_ModelID,
		HTuple hv_MinScale, HTuple hv_MaxScale, HTuple hv_MinScore, 
		HTuple *hv_Scale, HTuple *hv_Score);
	void find_material_circle(HObject ho_Image, HTuple hv_ModelID, HTuple hv_ScaleMin,
		HTuple hv_ScaleMax, HTuple hv_MinScore, HTuple *hv_Row, HTuple *hv_Column, HTuple *hv_Radius,
		HTuple *hv_Scale, HTuple *hv_Score);
};

extern HOPERATOR_API int nHOperator;

HOPERATOR_API int fnHOperator(void);
