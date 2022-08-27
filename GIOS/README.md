## Example environment setup
```
Here’s how I setup my environment using Docker + VSCode.
You need to download Docker desktop and install the Docker extension and Remote extension for VSCode.
Pull the image from dockerhub by running “docker pull gtomscs6200/sum22-environment” in your terminal.
Open Docker desktop and click the blue”RUN” button. Under the optional settings, map a host directory to the container
In my example, I used the following parameters:
Container Name: CS6200
Host Path: C:\Users\<UserName>\Desktop\CS6200\Projects
Container Path: /root/cs6200/Projects
Open VS Code and install the Docker extension and Remote Extension
Click on the Docker Extension icon and view the list of individual containers. Right-click on the container that you created (e.g. cs6200) and click “Attach Visual Studio Code”
A new window of VS code should pop up which is how you will primarily be editing your code in the container directly. If you click on File->Open Folder, you should be able to find the “Projects” directory you mapped.
From there, you can open a terminal and use git to clone the class projects to the C:\Users\<UserName>\Desktop\CS6200\Projects directory on your PC and it will automatically be shown in the remote VSCode file explorer...
```