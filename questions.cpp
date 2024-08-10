#include "questions.h"

// Example singel answer
std::vector<SingleAnswerQuestion> getSingleAnswerQuestions() {
    return {
        {"Every employee of your company has a Google account. Your operational team needs to manage a large number of instances on Compute Engine. Each member of this team needs only administrative access to the servers. Your security team wants to ensure that the deployment of credentials is operationally efficient and must be able to determine who accessed a given instance. What should you do?",
            "Generate a new SSH key pair. Give the private key to each member of your team. Configure the public key in the metadata of each instance.",
            "Ask each member of the team to generate a new SSH key pair and to send you their public key. Use a configuration management tool to deploy those keys on each instance.",
            "Ask each member of the team to generate a new SSH key pair and to add the public key to their Google account. Grant the `compute.osAdminLogin` role to the Google group corresponding to this team.",
            "Generate a new SSH key pair. Give the private key to each member of your team. Configure the public key as a project-wide public SSH key in your Cloud Platform project and allow project-wide public SSH keys on each instance.",
            'C'},
    };
}

// Example multiple answer
std::vector<MultipleAnswerQuestion> getMultipleAnswerQuestions() {
    return {
        {"Your company implemented BigQuery as an enterprise data warehouse. Users from multiple business units run queries on this data warehouse. However, you notice that query costs for BigQuery are very high, and you need to control costs. Which two methods should you use? (Choose two.)",
         "Split the users from business units into multiple projects.",
         "Apply a user- or project-level custom query quota for BigQuery data warehouse.",
         "Create separate copies of your BigQuery data warehouse for each business unit.",
         "Split your BigQuery data warehouse into multiple data warehouses for each business unit.",
         "Change your BigQuery query model from on-demand to flat rate. Apply the appropriate number of slots to each Project.",
         {"B", "E"}}
    };
}
