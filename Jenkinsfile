pipeline {
    agent any

    environment {
        BUILD_DIR = 'build'
    }

    stages {
        stage('Checkout') {
            steps {
                // Checkout the source code from your repository
                checkout([$class: 'GitSCM', branches: [[name: '*/main']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: 'Def', url: 'https://github.com/Scorza9/googletest']]])
            }
        }

        stage('Build') {
            steps {
                // Create build directory
                sh "mkdir -p ${BUILD_DIR}"

                // Run CMake and build the project
                dir(BUILD_DIR) {
                    sh 'cmake ..'
                    sh 'make'
                }
            }
        }

        stage('Test') {
            steps {
                // Run tests with Google Test
                dir(BUILD_DIR) {
                    sh './main'
                }
            }
        }
    }

    post {
        always {
            // Clean up build directory
            sh "rm -rf ${BUILD_DIR}"
        }
    }
}
