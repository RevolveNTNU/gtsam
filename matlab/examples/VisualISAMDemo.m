% VisualISAMDemo: runs VisualSLAM iSAM demo in a GUI
% Authors: Duy Nguyen Ta

% Make sure global variables are visible on command prompt
% so you can examine how they change as you step through
global TRIANGLE NCAMERAS SHOW_IMAGES 
global HARD_CONSTRAINT POINT_PRIORS BATCH_INIT REORDER_INTERVAL ALWAYS_RELINEARIZE 
global SAVE_GRAPH PRINT_STATS DRAW_INTERVAL CAMERA_INTERVAL DRAW_TRUE_POSES 
global SAVE_FIGURES SAVE_GRAPHS SHOW_TIMING
global points K cameras odometry 
global poseNoise pointNoise odometryNoise measurementNoise
global frame_i isam newFactors initialEstimates result

% Start GUI
VisualISAM_gui