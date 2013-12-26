

#ifndef DL_EXTRUSION_H
#define DL_EXTRUSION_H

#include <math.h>

class DL_Extrusion {

public:

    /**
     * Default constructor.
     */
    DL_Extrusion() {
		direction = new double[3];
        setDirection(0.0, 0.0, 1.0);
        setElevation(0.0);
    }


    /**
     * Destructor.
     */
	~DL_Extrusion() {
		delete direction ;
    }


    /**
     * Constructor for DXF extrusion.
     *
     * @param direction Vector of axis along which the entity shall be extruded
	 *                  this is also the Z axis of the Entity coordinate system
     * @param elevation Distance of the entities XY plane from the origin of the
	 *                  world coordinate system
     */
    DL_Extrusion(double dx, double dy, double dz, double elevation) {
		direction = new double[3];
		setDirection(dx, dy, dz);
        setElevation(elevation);
    }



    /**
     * Sets the direction vector. 
     */
    void setDirection(double dx, double dy, double dz) {
		direction[0]=dx;
        direction[1]=dy;
        direction[2]=dz;
    }



    /**
     * @return direction vector.
     */
    double* getDirection() const {
        return direction;
    }



    /**
     * @return direction vector.
     */
    void getDirection(double dir[]) const {
        dir[0]=direction[0];
        dir[1]=direction[1];
        dir[2]=direction[2];
    }



    /**
     * Sets the elevation.
     */
    void setElevation(double elevation) {
        this->elevation = elevation;
    }



    /**
     * @return Elevation.
     */
    double getElevation() const {
        return elevation;
    }



    /**
     * Copies extrusion (deep copies) from another extrusion object.
     */
    DL_Extrusion operator = (const DL_Extrusion& extru) {
        setDirection(extru.direction[0], extru.direction[1], extru.direction[2]);
        setElevation(extru.elevation);

        return *this;
    }



private:
	double *direction;
	double elevation;
};

#endif

