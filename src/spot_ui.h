#ifndef SPOT_UI_H
#define SPOT_UI_H

#include <stdio.h>


#include <ros/ros.h>
#include <std_msgs/ColorRGBA.h>
#include <std_srvs/Empty.h>
#include <std_srvs/Trigger.h>

#include <std_msgs/String.h>
#include <std_msgs/Bool.h>

#ifndef Q_MOC_RUN
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QRadioButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QApplication>
#include <QWidget>
#include "QSlider"
#include <QCheckBox>
#include <QFont>

#include <rviz/panel.h>
#endif

class QLineEdit;
class QPushButton;

namespace spot_ui {
class spot_panel : public rviz::Panel {
  Q_OBJECT
 public:
  spot_panel(QWidget* parent = 0);
  virtual void load(const rviz::Config& config);
  virtual void save(rviz::Config config) const;

 public Q_SLOTS:
  
  void on_spot_claim_click();
  void on_spot_power_on_click();
  void on_spot_stand_click();
  void on_spot_sit_click();
  void on_spot_power_off_click();
  void on_spot_release_click();
  void on_spot_estop_gentle_click();
  void on_spot_estop_hard_click();

  
  void on_state_change_click(int state);

protected Q_SLOTS:

 protected:
  
  QFont* font;

  QSlider* button_select_state;
  ros::Publisher planner_client_set_state;

  QLabel* stateLabel;

  
  QPushButton* button_spot_claim;
  ros::ServiceClient spot_claim;

  QPushButton* button_spot_power_on;
  ros::ServiceClient spot_power_on;
  
  QPushButton* button_spot_stand;
  ros::ServiceClient spot_stand;

  QPushButton* button_spot_sit;
  ros::ServiceClient spot_sit;

  QPushButton* button_spot_power_off;
  ros::ServiceClient spot_power_off;

  QPushButton* button_spot_release;
  ros::ServiceClient spot_release;

  QPushButton* button_spot_estop_gentle;
  ros::ServiceClient spot_estop_gentle;

  QPushButton* button_spot_estop_hard;
  ros::ServiceClient spot_estop_hard;



  bool claimed = false;
  bool powered_on = false;
  bool standing = false;
  bool sitting = false;
  bool poweref_off = false;
  bool released = false;


 
  ros::NodeHandle nh;
};

}  // namespace spot_ui

#endif  // SPOT_UI_H
