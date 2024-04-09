#ifndef _CUSTOMCLUSTER_H
#define _CUSTOMCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>

/******************************************************************************
                    Definitions section
******************************************************************************/






#define CUSTOM_SERVER_CLUSTERS_COUNT     6  //4+1+1         //sankar
 
#define CUSTOM_CLIENT_CLUSTERS_COUNT   4+1 

#define CUSTOM_SERVER_CLUSTER_INIT_COUNT    CUSTOM_SERVER_CLUSTERS_COUNT

#define CUSTOM_CLIENT_CLUSTER_INIT_COUNT    CUSTOM_CLIENT_CLUSTERS_COUNT

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_Cluster_t customServerClusters[CUSTOM_SERVER_CLUSTERS_COUNT];
extern ClusterId_t customServerClusterIds[CUSTOM_SERVER_CLUSTERS_COUNT];
extern void (*customServerClusterInitFunctions[CUSTOM_SERVER_CLUSTER_INIT_COUNT])();

extern ZCL_Cluster_t customClientClusters[CUSTOM_CLIENT_CLUSTERS_COUNT];
extern ClusterId_t customClientClusterIds[CUSTOM_CLIENT_CLUSTERS_COUNT];
extern void (*customClientClusterInitFunctions[CUSTOM_CLIENT_CLUSTER_INIT_COUNT])();


#endif // _CUSTOMCLUSTER_H

// eof customClusters.h
