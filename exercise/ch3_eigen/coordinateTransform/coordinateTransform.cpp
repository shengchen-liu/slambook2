/*
The robot No. 1 and the robot No. 2 are located in the world coordinate system. We use the world coordinate system as W, robot coordinate system as R1 and R2. 
The pose of the robot1 is q1 = [0.35, 0.2, 0.3, 0.1]^T, t1 = [0.3, 0.1, 0.1]^T.  
The pose of the robot2 is q2 = [−0.5, 0.4, −0.1, 0.2]T, t2 = [−0.1, 0.5, 0.3]T.  
Here q and t express TRk,W , k = 1, 2, which is the world coordinate system to the robot coordinate system. 
Now, assume that robot No. 1 sees a point in its own coordinate system with coordinates of pR1 = [0.5, 0, 0.2]T, find the coordinates of the vector in the radish No. 2 coordinate system.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<Eigen/Core>
#include<Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv) {
    Quaterniond q1(0.35, 0.2, 0.3, 0.1), q2(-0.5, 0.4, -0.1, 0.2);
    q1.normalize();
    q2.normalize();
    Vector3d t1(0.3, 0.1, 0.1), t2(-0.1, 0.5, 0.3);
    Vector3d p1(0.5, 0, 0.2);

    Isometry3d T1w(q1), T2w(q2);
    T1w.pretranslate(t1);
    T2w.pretranslate(t2);

    Vector3d p2 = T2w * T1w.inverse() * p1;
    cout << endl << p2.transpose() << endl;
    return 0;
}