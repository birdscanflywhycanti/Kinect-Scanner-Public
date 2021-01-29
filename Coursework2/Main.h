#pragma once
void loadDepth(long*& lDepthToRgbMap, float*& fdest, const BYTE* start);
void loadRgb(const USHORT*& curr, float*& fdest, long*& lDepthToRgbMap);
int kinectSetup();
void storeDepthAtPoint(const USHORT*& curr, int width, int height, float*& fdest, long*& depth2rgb);
void storeRGBDataAtPoint(long*& ldepthToRgbMap, float*& fdest, const BYTE* start);
void getData(GLubyte* dest, HANDLE* stream, std::string type);
void getKinectData();
void rotateCamera();
void drawKinectData();
void bufferSetup();
void cameraSetup();

