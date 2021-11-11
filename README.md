# Robotics-Projects
Experimentations with robots


# Git Cheatsheet

## Starting
 - Download git 
   - Windows: https://git-scm.com/download/win
   - Mac: https://git-scm.com/download/mac
   - Ubuntu: `sudo apt-get install git`
 - Make a folder called git
 - In that new folder, download the Repo `git clone https://github.com/grimwolf007/Robotics-Projects.git`

## The Workflow
 - Make issues based on what you want to do
 - Make a branch `git branch <branch name>`
 - Checkout that branch `git checkout <branch name>`
 - Make edits on that branch until the issue is resolved, commiting to your local host when you get something done
   - To commit:
     - `git status` to see what you changed
     - `git add <file or directory>` to stage the files for a commit
     - `git commit` to "save" your work (you can always rollback changes to a last commit)
   - If there is a change to the master branch in that time pull and merge the changes `git pull`
 - Once the issue is resolved push all of your local commits to the github server `git push`
 - If you are pushing code it is best to have it reviewed before pushing it to the master branch (create pull request in github)
 - If it is just a change to a Readme or cosmetic change feel free to push directly to master
