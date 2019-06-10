#ifdef UNITTEST
#include "gtest.h"
#include "slavespi.h"


TEST(SlaveSPI, encryption)
{
	int x= 1;
	EXPECT_EQ(x,1);
}

TEST(gps, convertDegreesToDeci)
{
//	GPSLocation in0 =
//			{ 51031580, 3421810 };
//	GPSLocation out0 =
//			{ 51052633, 3703016 }; 

//
//	in0.convertDegreesToDeci();
//	EXPECT_EQ(out0.myLatitude, in0.myLatitude);
//	EXPECT_EQ(out0.myLongitude, in0.myLongitude);
}

TEST(gps, distance)
{
//	GPSLocation dist1_1 ={ 51057580, 3699610 };
//	GPSLocation dist1_2 ={ 51054420, 3704980 };
//	long dist1 = 51406; //in cm 51410; //in cm

//	EXPECT_EQ(0, dist1_1.distance(dist1_1));
//	EXPECT_EQ(0, dist1_2.distance(dist1_2));
//	EXPECT_EQ(dist1, dist1_2.distance(dist1_1));
//	EXPECT_EQ(dist1, dist1_1.distance(dist1_2));

}



#endif
