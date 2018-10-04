//Implement the haversine function
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define M_PI                     3.14159265358979323846
#define EARTH_RADIUS_IN_METRES   6372797
#define MIN_LAT                  -90
#define MAX_LAT                  90
#define MIN_LON                  -180
#define MAX_LON                  180

double degrees_to_radians(double degrees){
      return (M_PI / 180) * degrees;
}

double radians_to_degrees(double radians){
      return (180 / M_PI) * radians;
}

bool valid_location(double latitude, double longitude){
      return ((latitude >= MIN_LAT) && (latitude <= MAX_LAT) &&
      (longitude >= MIN_LON) && (longitude <= MAX_LON));
}

double haversine(double latitude1, double longitude1, double latitude2, double longitude2){
      double delta_latitude = (latitude2 - latitude1)/2;
      double delta_longitude = (longitude2 - longitude1)/2;

      double sin1 = sin(delta_latitude);
      double sin2 = sin(delta_longitude);

      double cos1 = cos(latitude1);
      double cos2 = cos(latitude2);

      double x = sin1 * sin1 + cos1*cos2*sin2*sin2;

      return 2*EARTH_RADIUS_IN_METRES*asin(sqrt(x));
}

int main(int argc, char *argv[]){
      if(argc != 5){
        printf("Error, must have 4 arguments!");
        exit(EXIT_FAILURE);
      }
      else{
        double lat1 = atof(argv[1]);
        double lat2 = atof(argv[3]);
        double long1 = atof(argv[2]);
        double long2 = atof(argv[4]);

        if(valid_location(lat1, long1) == false){
            printf("Invalid Location 1 %f %f !", lat1, long1);
            exit(EXIT_FAILURE);
        }
        else if(valid_location(lat2, long2) == false){
            printf("Invalid Location 2 %f %f !", lat2, long2);
        }
        else{
            printf("Distance = %fm apart", haversine(lat1, long1, lat2, long2));
            exit(EXIT_SUCCESS);
        }
      }
   }
