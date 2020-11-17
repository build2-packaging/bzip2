# Glue buildfile that "pulls" all the packages in the project.
#
import pkgs = libbzip2/ bzip2/

./: $pkgs
