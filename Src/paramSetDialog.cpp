#include "paramSetDialog.h"
#include "ui_paramSetDialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//将所有参数写入param.ini文件中
void Dialog::writeParam()
{
    //创建配置文件
    QSettings *pIni = new QSettings("./params.ini", QSettings::IniFormat);
    double temp;

    //*************************Cam1*****************************//
    //圆形ROI
    temp = ui->p_cam1_circle_row->value();
    pIni->setValue("/Cam1/circle_roi_row", temp);
    temp = ui->p_cam1_circle_col->value();
    pIni->setValue("/Cam1/circle_roi_col", temp);
    temp = ui->p_cam1_circle_radius->value();
    pIni->setValue("/Cam1/circle_roi_radius", temp);
    //物料参数
    temp = ui->p_cam1_material_radius->value();
    pIni->setValue("/Cam1/material_radius", temp);
    temp = ui->p_cam1_material_offsetlow->value();
    pIni->setValue("/Cam1/material_offsetlow", temp);
    temp = ui->p_cam1_material_offsethigh->value();
    pIni->setValue("/Cam1/material_offsethigh", temp);
    //找圆心模板匹配参数
    temp = ui->p_cam1_circle_model_scalemin->value();
    pIni->setValue("/Cam1/circle_model_scalemin", temp);
    temp = ui->p_cam1_circle_model_scalemax->value();
    pIni->setValue("/Cam1/circle_model_scalemax", temp);
    temp = ui->p_cam1_circle_model_minscore->value();
    pIni->setValue("/Cam1/circle_model_minscore", temp);
    //找特征模板匹配参数
    temp = ui->p_cam1_feature_model_scalemin->value();
    pIni->setValue("/Cam1/feature_model_scalemin", temp);
    temp = ui->p_cam1_feature_model_scalemax->value();
    pIni->setValue("/Cam1/feature_model_scalemax", temp);
    temp = ui->p_cam1_feature_model_minscore->value();
    pIni->setValue("/Cam1/feature_model_minscore", temp);

    //*************************Cam2*****************************//
    //圆形ROI
    temp = ui->p_cam2_circle_row->value();
    pIni->setValue("/Cam2/circle_roi_row", temp);
    temp = ui->p_cam2_circle_col->value();
    pIni->setValue("/Cam2/circle_roi_col", temp);
    temp = ui->p_cam2_circle_radius->value();
    pIni->setValue("/Cam2/circle_roi_radius", temp);
    //物料参数
    temp = ui->p_cam2_material_radius->value();
    pIni->setValue("/Cam2/material_radius", temp);
    temp = ui->p_cam2_material_offsetlow->value();
    pIni->setValue("/Cam2/material_offsetlow", temp);
    temp = ui->p_cam2_material_offsethigh->value();
    pIni->setValue("/Cam2/material_offsethigh", temp);
    //找圆心模板匹配参数
    temp = ui->p_cam2_circle_model_scalemin->value();
    pIni->setValue("/Cam2/circle_model_scalemin", temp);
    temp = ui->p_cam2_circle_model_scalemax->value();
    pIni->setValue("/Cam2/circle_model_scalemax", temp);
    temp = ui->p_cam2_circle_model_minscore->value();
    pIni->setValue("/Cam2/circle_model_minscore", temp);
    //找特征模板匹配参数
    temp = ui->p_cam2_feature_model_scalemin->value();
    pIni->setValue("/Cam2/feature_model_scalemin", temp);
    temp = ui->p_cam2_feature_model_scalemax->value();
    pIni->setValue("/Cam2/feature_model_scalemax", temp);
    temp = ui->p_cam2_feature_model_minscore->value();
    pIni->setValue("/Cam2/feature_model_minscore", temp);

    //*************************Cam3*****************************//
    //圆形ROI
    temp = ui->p_cam3_circle_row->value();
    pIni->setValue("/Cam3/circle_roi_row", temp);
    temp = ui->p_cam3_circle_col->value();
    pIni->setValue("/Cam3/circle_roi_col", temp);
    temp = ui->p_cam3_circle_radius->value();
    pIni->setValue("/Cam3/circle_roi_radius", temp);
    //物料参数
    temp = ui->p_cam3_material_radius->value();
    pIni->setValue("/Cam3/material_radius", temp);
    temp = ui->p_cam3_material_offsetlow->value();
    pIni->setValue("/Cam3/material_offsetlow", temp);
    temp = ui->p_cam3_material_offsethigh->value();
    pIni->setValue("/Cam3/material_offsethigh", temp);
    //找圆心模板匹配参数
    temp = ui->p_cam3_circle_model_scalemin->value();
    pIni->setValue("/Cam3/circle_model_scalemin", temp);
    temp = ui->p_cam3_circle_model_scalemax->value();
    pIni->setValue("/Cam3/circle_model_scalemax", temp);
    temp = ui->p_cam3_circle_model_minscore->value();
    pIni->setValue("/Cam3/circle_model_minscore", temp);
    //找特征模板匹配参数
    temp = ui->p_cam3_feature_model_scalemin->value();
    pIni->setValue("/Cam3/feature_model_scalemin", temp);
    temp = ui->p_cam3_feature_model_scalemax->value();
    pIni->setValue("/Cam3/feature_model_scalemax", temp);
    temp = ui->p_cam3_feature_model_minscore->value();
    pIni->setValue("/Cam3/feature_model_minscore", temp);

    //*************************Cam4*****************************//
    //圆形ROI
    temp = ui->p_cam4_circle_row->value();
    pIni->setValue("/Cam4/circle_roi_row", temp);
    temp = ui->p_cam4_circle_col->value();
    pIni->setValue("/Cam4/circle_roi_col", temp);
    temp = ui->p_cam4_circle_radius->value();
    pIni->setValue("/Cam4/circle_roi_radius", temp);
    //物料参数
    temp = ui->p_cam4_material_radius->value();
    pIni->setValue("/Cam4/material_radius", temp);
    temp = ui->p_cam4_material_offsetlow->value();
    pIni->setValue("/Cam4/material_offsetlow", temp);
    temp = ui->p_cam4_material_offsethigh->value();
    pIni->setValue("/Cam4/material_offsethigh", temp);
    //找圆心模板匹配参数
    temp = ui->p_cam4_circle_model_scalemin->value();
    pIni->setValue("/Cam4/circle_model_scalemin", temp);
    temp = ui->p_cam4_circle_model_scalemax->value();
    pIni->setValue("/Cam4/circle_model_scalemax", temp);
    temp = ui->p_cam4_circle_model_minscore->value();
    pIni->setValue("/Cam4/circle_model_minscore", temp);
    //找特征模板匹配参数
    temp = ui->p_cam4_feature_model_scalemin->value();
    pIni->setValue("/Cam4/feature_model_scalemin", temp);
    temp = ui->p_cam4_feature_model_scalemax->value();
    pIni->setValue("/Cam4/feature_model_scalemax", temp);
    temp = ui->p_cam4_feature_model_minscore->value();
    pIni->setValue("/Cam4/feature_model_minscore", temp);

    //*************************Cam5*****************************//
    //圆形ROI
    temp = ui->p_cam5_circle_row->value();
    pIni->setValue("/Cam5/circle_roi_row", temp);
    temp = ui->p_cam5_circle_col->value();
    pIni->setValue("/Cam5/circle_roi_col", temp);
    temp = ui->p_cam5_circle_radius->value();
    pIni->setValue("/Cam5/circle_roi_radius", temp);
    //物料参数
    temp = ui->p_cam5_material_radius->value();
    pIni->setValue("/Cam5/material_radius", temp);
    temp = ui->p_cam5_material_offsetlow->value();
    pIni->setValue("/Cam5/material_offsetlow", temp);
    temp = ui->p_cam5_material_offsethigh->value();
    pIni->setValue("/Cam5/material_offsethigh", temp);
    //找圆心模板匹配参数
    temp = ui->p_cam5_circle_model_scalemin->value();
    pIni->setValue("/Cam5/circle_model_scalemin", temp);
    temp = ui->p_cam5_circle_model_scalemax->value();
    pIni->setValue("/Cam5/circle_model_scalemax", temp);
    temp = ui->p_cam5_circle_model_minscore->value();
    pIni->setValue("/Cam5/circle_model_minscore", temp);
    //找特征模板匹配参数
    temp = ui->p_cam5_feature_model_scalemin->value();
    pIni->setValue("/Cam5/feature_model_scalemin", temp);
    temp = ui->p_cam5_feature_model_scalemax->value();
    pIni->setValue("/Cam5/feature_model_scalemax", temp);
    temp = ui->p_cam5_feature_model_minscore->value();
    pIni->setValue("/Cam5/feature_model_minscore", temp);
}

//读取param.ini中的参数，并显示在UI上
void Dialog::dispParam()
{
    //创建配置文件
    QSettings *pIni = new QSettings("./params.ini", QSettings::IniFormat);
    double temp;

    //*************************Cam1*****************************//
    //圆形ROI
    temp = pIni->value("/Cam1/circle_roi_row").toDouble();
    ui->p_cam1_circle_row->setValue(temp);
    temp = pIni->value("/Cam1/circle_roi_col").toDouble();
    ui->p_cam1_circle_col->setValue(temp);
    temp = pIni->value("/Cam1/circle_roi_radius").toDouble();
    ui->p_cam1_circle_radius->setValue(temp);
    //物料参数
    temp = pIni->value("/Cam1/material_radius").toDouble();
    ui->p_cam1_material_radius->setValue(temp);
    temp = pIni->value("/Cam1/material_offsetlow").toDouble();
    ui->p_cam1_material_offsetlow->setValue(temp);
    temp = pIni->value("/Cam1/material_offsethigh").toDouble();
    ui->p_cam1_material_offsethigh->setValue(temp);
    //找圆心模板匹配参数
    temp = pIni->value("/Cam1/circle_model_scalemin").toDouble();
    ui->p_cam1_circle_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam1/circle_model_scalemax").toDouble();
    ui->p_cam1_circle_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam1/circle_model_minscore").toDouble();
    ui->p_cam1_circle_model_minscore->setValue(temp);
    //找特征模板匹配参数
    temp = pIni->value("/Cam1/feature_model_scalemin").toDouble();
    ui->p_cam1_feature_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam1/feature_model_scalemax").toDouble();
    ui->p_cam1_feature_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam1/feature_model_minscore").toDouble();
    ui->p_cam1_feature_model_minscore->setValue(temp);

    //*************************Cam2*****************************//
    //圆形ROI
    temp = pIni->value("/Cam2/circle_roi_row").toDouble();
    ui->p_cam2_circle_row->setValue(temp);
    temp = pIni->value("/Cam2/circle_roi_col").toDouble();
    ui->p_cam2_circle_col->setValue(temp);
    temp = pIni->value("/Cam2/circle_roi_radius").toDouble();
    ui->p_cam2_circle_radius->setValue(temp);
    //物料参数
    temp = pIni->value("/Cam2/material_radius").toDouble();
    ui->p_cam2_material_radius->setValue(temp);
    temp = pIni->value("/Cam2/material_offsetlow").toDouble();
    ui->p_cam2_material_offsetlow->setValue(temp);
    temp = pIni->value("/Cam2/material_offsethigh").toDouble();
    ui->p_cam2_material_offsethigh->setValue(temp);
    //找圆心模板匹配参数
    temp = pIni->value("/Cam2/circle_model_scalemin").toDouble();
    ui->p_cam2_circle_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam2/circle_model_scalemax").toDouble();
    ui->p_cam2_circle_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam2/circle_model_minscore").toDouble();
    ui->p_cam2_circle_model_minscore->setValue(temp);
    //找特征模板匹配参数
    temp = pIni->value("/Cam2/feature_model_scalemin").toDouble();
    ui->p_cam2_feature_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam2/feature_model_scalemax").toDouble();
    ui->p_cam2_feature_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam2/feature_model_minscore").toDouble();
    ui->p_cam2_feature_model_minscore->setValue(temp);

    //*************************Cam2*****************************//
    //圆形ROI
    temp = pIni->value("/Cam3/circle_roi_row").toDouble();
    ui->p_cam3_circle_row->setValue(temp);
    temp = pIni->value("/Cam3/circle_roi_col").toDouble();
    ui->p_cam3_circle_col->setValue(temp);
    temp = pIni->value("/Cam3/circle_roi_radius").toDouble();
    ui->p_cam3_circle_radius->setValue(temp);
    //物料参数
    temp = pIni->value("/Cam3/material_radius").toDouble();
    ui->p_cam3_material_radius->setValue(temp);
    temp = pIni->value("/Cam3/material_offsetlow").toDouble();
    ui->p_cam3_material_offsetlow->setValue(temp);
    temp = pIni->value("/Cam3/material_offsethigh").toDouble();
    ui->p_cam3_material_offsethigh->setValue(temp);
    //找圆心模板匹配参数
    temp = pIni->value("/Cam3/circle_model_scalemin").toDouble();
    ui->p_cam3_circle_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam3/circle_model_scalemax").toDouble();
    ui->p_cam3_circle_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam3/circle_model_minscore").toDouble();
    ui->p_cam3_circle_model_minscore->setValue(temp);
    //找特征模板匹配参数
    temp = pIni->value("/Cam3/feature_model_scalemin").toDouble();
    ui->p_cam3_feature_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam3/feature_model_scalemax").toDouble();
    ui->p_cam3_feature_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam3/feature_model_minscore").toDouble();
    ui->p_cam3_feature_model_minscore->setValue(temp);

    //*************************Cam4*****************************//
    //圆形ROI
    temp = pIni->value("/Cam4/circle_roi_row").toDouble();
    ui->p_cam4_circle_row->setValue(temp);
    temp = pIni->value("/Cam4/circle_roi_col").toDouble();
    ui->p_cam4_circle_col->setValue(temp);
    temp = pIni->value("/Cam4/circle_roi_radius").toDouble();
    ui->p_cam4_circle_radius->setValue(temp);
    //物料参数
    temp = pIni->value("/Cam4/material_radius").toDouble();
    ui->p_cam4_material_radius->setValue(temp);
    temp = pIni->value("/Cam4/material_offsetlow").toDouble();
    ui->p_cam4_material_offsetlow->setValue(temp);
    temp = pIni->value("/Cam4/material_offsethigh").toDouble();
    ui->p_cam4_material_offsethigh->setValue(temp);
    //找圆心模板匹配参数
    temp = pIni->value("/Cam4/circle_model_scalemin").toDouble();
    ui->p_cam4_circle_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam4/circle_model_scalemax").toDouble();
    ui->p_cam4_circle_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam4/circle_model_minscore").toDouble();
    ui->p_cam4_circle_model_minscore->setValue(temp);
    //找特征模板匹配参数
    temp = pIni->value("/Cam4/feature_model_scalemin").toDouble();
    ui->p_cam4_feature_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam4/feature_model_scalemax").toDouble();
    ui->p_cam4_feature_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam4/feature_model_minscore").toDouble();
    ui->p_cam4_feature_model_minscore->setValue(temp);

    //*************************Cam5*****************************//
    //圆形ROI
    temp = pIni->value("/Cam5/circle_roi_row").toDouble();
    ui->p_cam5_circle_row->setValue(temp);
    temp = pIni->value("/Cam5/circle_roi_col").toDouble();
    ui->p_cam5_circle_col->setValue(temp);
    temp = pIni->value("/Cam5/circle_roi_radius").toDouble();
    ui->p_cam5_circle_radius->setValue(temp);
    //物料参数
    temp = pIni->value("/Cam5/material_radius").toDouble();
    ui->p_cam5_material_radius->setValue(temp);
    temp = pIni->value("/Cam5/material_offsetlow").toDouble();
    ui->p_cam5_material_offsetlow->setValue(temp);
    temp = pIni->value("/Cam5/material_offsethigh").toDouble();
    ui->p_cam5_material_offsethigh->setValue(temp);
    //找圆心模板匹配参数
    temp = pIni->value("/Cam5/circle_model_scalemin").toDouble();
    ui->p_cam5_circle_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam5/circle_model_scalemax").toDouble();
    ui->p_cam5_circle_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam5/circle_model_minscore").toDouble();
    ui->p_cam5_circle_model_minscore->setValue(temp);
    //找特征模板匹配参数
    temp = pIni->value("/Cam5/feature_model_scalemin").toDouble();
    ui->p_cam5_feature_model_scalemin->setValue(temp);
    temp = pIni->value("/Cam5/feature_model_scalemax").toDouble();
    ui->p_cam5_feature_model_scalemax->setValue(temp);
    temp = pIni->value("/Cam5/feature_model_minscore").toDouble();
    ui->p_cam5_feature_model_minscore->setValue(temp);
}

void Dialog::on_pb_save_param_clicked()
{
    writeParam();
    emit updateParam();
}

void Dialog::on_pb_clear_pic_clicked()
{
    emit clearHistoryPicture();
}
