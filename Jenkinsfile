#!/usr/bin/env groovy

pipeline {
    agent any

    options {
        buildDiscarder(logRotator(numToKeepStr: '10'))
    }

    environment {
        HTTP_PROXY="${HTTP_PROXY}"
        HTTPS_PROXY="${HTTPS_PROXY}"
        NO_PROXY="${NO_PROXY}"
        SONAR_LOGIN_KEY = credentials('SONAR_LOGIN_KEY')
    }

    stages {

        stage('Setup') {
            steps {
                sh 'docker-compose -f gcc-with-sonar-compose.yml build'
            }
        }

        stage('Build') {
            agent {
                docker {
                    image 'oasis-gcc-sonar:4.9'
                    args '-u ${JENKINS_UID}'
                }
            }
            steps {
                sh 'id'
                sh 'gcc --coverage -o CalculatorTest -I ./src -I /usr/src/gtest/include/ ./src/Calculator.cpp ./test/CalculatorTest.cpp -lgtest -lstdc++ -lm -lpthread'
                sh './CalculatorTest'
                sh 'gcov Calculator'
            }
        }
        stage('SonarQube (Quality)') {
            agent {
                docker {
                    // to run as non-root:
                    // $ docker run -v ~/.m2:/var/maven/.m2 -ti --rm -u 1000 -e MAVEN_CONFIG=/var/maven/.m2 maven mvn -Duser.home=/var/maven archetype:generate
                    image 'oasis-gcc-sonar:4.9'
                    args '-u ${JENKINS_UID} -e MAVEN_OPTS=${MAVEN_OPTS} -v ${JENKINS_HOST_HOME}:/var/jenkins -v ${MAVEN_REPO_DIR}:/var/jenkins/.m2 -e SONAR_HOST_URL=${SONAR_HOST_URL} -e SONAR_LOGIN_KEY=${SONAR_LOGIN_KEY}'
                }
            }
//            when {
//                branch "master"
//            }

            steps {
                sh 'build-wrapper-linux-x86-64 --out-dir bw-output gcc -o CalculatorTest -I ./src -I /usr/src/gtest/include/ ./src/Calculator.cpp ./test/CalculatorTest.cpp -lgtest -lstdc++ -lm -lpthread'
                sh 'sonar-scanner -Dsonar.host.url=${SONAR_HOST_URL} -Dsonar.login=${SONAR_LOGIN_KEY} -Dsonar.projectKey=graichen_calculator-unit-test-example-java -Dsonar.organization=graichen -Dsonar.sources=. -Dsonar.cfamily.build-wrapper-output=bw-output -Dsonar.cfamily.gcov.reportsPath=.'
            }
        }

    }
//    post {
//        unstable {
//            mail to: "${env.CHANGE_AUTHOR_EMAIL}",
//                    subject: "Unstable Pipeline: ${currentBuild.fullDisplayName}",
//                    body: "Something is wrong with ${env.BUILD_URL}"
//        }
//        failure {
//            mail to: "${env.CHANGE_AUTHOR_EMAIL}",
//                    subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
//                    body: "Something is wrong with ${env.BUILD_URL}"
//        }
//        aborted {
//            mail to: "${env.CHANGE_AUTHOR_EMAIL}",
//                    subject: "Aborted Pipeline: ${currentBuild.fullDisplayName}",
//                    body: "Something is wrong with ${env.BUILD_URL}"
//        }
//        changed {
//            mail to: "${env.CHANGE_AUTHOR_EMAIL}",
//                    subject: "Changed Pipeline: ${currentBuild.fullDisplayName}",
//                    body: "Something is changed with ${env.BUILD_URL}"
//        }
//    }
}
