FROM gcc:10.2

RUN apt-get update \
    && apt-get install -y unzip cmake libgtest-dev make

RUN mkdir /app

RUN cd /app || exit 1; \
    curl -k -o build-wrapper-linux-x86.zip https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip || exit 1; \
    filesize_build_wrapper=`stat --format=%s build-wrapper-linux-x86.zip` || exit 1; \
    echo "build_wrapper filesize = $filesize_build_wrapper" || exit 1; \
    if [ $filesize_build_wrapper -le 1000 ]; then echo "curl failed to download successfully"; exit 1; fi ; \
    unzip build-wrapper-linux-x86.zip || exit 1; \
    rm build-wrapper-linux-x86.zip || exit 1;

RUN cd /app || exit 1; \
    curl -k -o sonar-scanner-cli-4.4.0.2170-linux.zip https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.4.0.2170-linux.zip || exit 1; \
    filesize_sonar_scanner=`stat --format=%s sonar-scanner-cli-4.4.0.2170-linux.zip` || exit 1; \
    echo "sonar_scanner filesize = $filesize_sonar_scanner" || exit 1; \
    if [ $filesize_sonar_scanner -le 1000 ]; then echo "curl failed to download successfully"; exit 1; fi ; \
    unzip sonar-scanner-cli-4.4.0.2170-linux.zip || exit 1; \
    rm sonar-scanner-cli-4.4.0.2170-linux.zip || exit 1;

ENV PATH=$PATH:/app/build-wrapper-linux-x86:/app/sonar-scanner-4.4.0.2170-linux/bin

RUN cd  /usr/src/gtest || exit 1; \
    cmake CMakeLists.txt || exit 1; \
    make || exit 1; \
    cp *.a /usr/lib || exit 1;
