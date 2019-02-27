GUI_without_host.py and GUI_with_Host.py are on Raspberry Pi but only 1 should be use.
matlabGUI.mlapp is on a host computer that run Matlab, the MatlabGUI does not directly control the rover but instead control the other 2 onboard GUIs.

If we decide to use GUI_with_Host.py, we have to run it first and then run matlabGUI.mlapp. If we decide to use the other one, matlabGUI.mlapp is not needed.
